<?php

    // configuration
    require("../includes/config.php");

    // current user ID
    $user_id = $_SESSION["id"];

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        
        // get a list of available stock
        $rows = query("SELECT symbol FROM portfolio WHERE id=?", $user_id);
    
        // else render form
        render("sell_form.php", ["title" => "Sell", "stocks" => $rows]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $symbol = isset($_POST["symbol"]) ? $_POST["symbol"] : null;
        
        // validate
        if(empty($symbol))
            apologize("You must select a stock to sell");
            
        // fetch how many shares the user has of this stock
        $rows = query("SELECT shares FROM portfolio WHERE id=? AND symbol = ?", $user_id, $symbol);
            
        if(empty($rows))
            apologize("You don't own any shares of this stock");
            
        // get number of shares
        $shares = $rows[0]["shares"];
            
        // lookup stock
        $stock = lookup($symbol);
        
        // calculate return value
        $value = $shares * $stock["price"];
        
        // track history
        query("INSERT INTO history (user_id, transaction, symbol, shares, price) VALUES(?, ?, ?, ?, ?)", $user_id, "SELL", $symbol, $shares, $value);
        
        // delete stock from user portfolio
        query("DELETE FROM portfolio WHERE id = ? AND symbol = ?", $user_id, $symbol);
        
        // add return in value to the users cash
         query("UPDATE users SET cash = cash + ? WHERE id = ?", $value, $user_id);
        
        // redirect user back to portfolio
        redirect("index.php");
    }

?>
