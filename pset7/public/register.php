<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $username = $_POST["username"];
        $password = $_POST["password"];
        $confirmation = $_POST["confirmation"];
    
        // validation
        if(empty($username) || $password !== $confirmation)
            apologize("Invalid username and/or password.");
        
        // try insert user in database
        $result = query("INSERT INTO users (username, hash, cash) VALUES(?, ?, 10000.00)", $username, crypt($password));

        // check insert result
        if($result === false)
            apologize("Username is already in use by another user.");
            
        // get insert ID
        $rows = query("SELECT LAST_INSERT_ID() AS id");
        $inserted_id = $rows[0]["id"];
        
        // store ID in session so that user is logged in
        $_SESSION["id"] = $inserted_id;
        
        // redirect user to home page
        redirect("index.php");
    }

?>
