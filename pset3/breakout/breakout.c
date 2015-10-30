//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// paddle dimensions
#define PADDLE_HEIGHT 10
#define PADDLE_WIDTH 80
#define PADDLE_X (WIDTH - PADDLE_WIDTH) / 2
#define PADDLE_Y HEIGHT - PADDLE_HEIGHT - 50

// size of the ball
#define BALL_DX 0.03
#define BALL_VEL BALL_DX*BALL_DX*2
#define BALL_DY(dx) (sqrt(BALL_VEL - (dx*dx)))

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// spacing between bricks
#define BRICK_SPACING 4
#define BRICKS_START_Y 50

// radius of ball in pixels
#define RADIUS 10
#define DIAMETER RADIUS * 2

// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);
    double multiplier = drand48()/20;
    int direction = (rand()%2) * 2 - 1;
    double velocityX = direction * multiplier;
    double velocityY = .05;

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;

    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {

        // Paddle movement
        GEvent event = getNextEvent(MOUSE_EVENT);
        if (event != NULL && getEventType(event) == MOUSE_MOVED)
        {
            // ensure circle follows top cursor
            double x = getX(event) - getWidth(paddle) / 2;
            double y = getY(event) - getWidth(paddle);
            double paddleY = getY(paddle);

            // make sure the paddle doesn't move outside the window
            if(x >= 0 && x <= WIDTH - PADDLE_WIDTH) {
                setLocation(paddle, x, paddleY);
            }
        }

        // ball bounce
        move(ball,velocityX,velocityY);
        double ballX = getX(ball);
        double ballY = getY(ball);

        // left or right bounce
        if ((ballX + DIAMETER >= WIDTH) || ballX <= 0)
            velocityX = -velocityX;

        // top bounce
        else if (ballY <= 0)
            velocityY = -velocityY;

        // ball lost
        else if (ballY + DIAMETER >= HEIGHT)
        {
            lives--;
            setLocation(ball, (WIDTH / 2) - RADIUS,(HEIGHT / 2) - RADIUS);
            setLocation(paddle, PADDLE_X, PADDLE_Y);
            waitForClick();
        }
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Get row color based on a row number
 */
string getRowColor(int row)
{
    string color = "RED";
    switch(row) {
        case 1:
            color = "ORANGE";
            break;
        case 2:
            color = "YELLOW";
            break;
        case 3:
            color = "GREEN";
            break;
        case 4:
            color = "BLUE";
            break;
        case 5:
            color = "PINK";
            break;
    }
    return color;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    double brickWidth = (WIDTH / COLS) - (BRICK_SPACING * 2);
    double brickHeight = ((HEIGHT / 7) / ROWS) - (BRICK_SPACING * 2);

    double y = BRICKS_START_Y;
    for(int i=0; i <= ROWS; i++) {
        for(int j=0; j <= COLS; j++) {
            double x = BRICK_SPACING + ((j+1) * BRICK_SPACING) + (j * brickWidth);
            GRect brick = newGRect(x, y, brickWidth, brickHeight);
            setColor(brick, getRowColor(i));
            setFilled(brick, true);
            add(window, brick);
        }
        y += (BRICK_SPACING * 2) + brickHeight;
    }
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    double x = (WIDTH - DIAMETER) / 2;
    double y = (HEIGHT - DIAMETER) / 2;
    GOval ball = newGOval(x, y, DIAMETER, DIAMETER);
    setColor(ball, "BLACK");
    setFilled(ball, true);
    add(window, ball);

    return ball;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // create the actual paddle
    GRect paddle = newGRect(PADDLE_X, PADDLE_Y, PADDLE_WIDTH, PADDLE_HEIGHT);
    setColor(paddle, "BLACK");
    setFilled(paddle, true);

    // add paddle to the screen
    add(window, paddle);

    return paddle;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
    return NULL;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
