<?php

    // configuration
    require("../includes/config.php");

    // current user ID
    $user_id = $_SESSION["id"];

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_form.php", ["title" => "Buy"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $symbol = strtoupper($_POST["symbol"]);
        $shares = $_POST["shares"];
        
        // validate
        if(empty($symbol))
            apologize("No symbol provided");
            
        // lookup stock
        $stock = lookup($symbol);
        
        // check if we found a stock item
        if($stock === false)
            apologize("Symbol not found");
            
        // validate shares number
        if(!preg_match("/^\d+$/", $shares))
            apologize("It's only possible to buy whole shares of stocks");
        if($shares == 0)
            apologize("It's not possible to buy zero shares of a stock");

        // calculate the price of this sale
        $price = $stock["price"] * $shares;
        
        // check if user has enough money to pay these shares
        $user = query("SELECT cash FROM users WHERE id=?", $user_id);
        $cash = $user[0]["cash"];
        if($price > $cash)
            apologize("You don't have enough money on your account to pay these shares");
        
        // track history
        query("INSERT INTO history (user_id, transaction, symbol, shares, price) VALUES(?, ?, ?, ?, ?)", $user_id, "BUY", $symbol, $shares, $price);
        
        // remove sale amout of user account cash
        query("UPDATE users SET cash = cash - ? WHERE id = ?", $price, $user_id);
            
        // add/update user portfolio
        $result = query("INSERT INTO portfolio (id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $user_id, $symbol, $shares);
            
        if($result === false)
            apologize("Failed to buy stock, try again later!");
        
        // redirect user to portfolio
        redirect("index.php");
        
    }

?>
