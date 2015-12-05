<?php

    // configuration
    require("../includes/config.php"); 

    // current user ID
    $user_id = $_SESSION["id"];

    // get stock portfolio
    $rows = query("SELECT * FROM portfolio WHERE id=?", $user_id);
    
    // get user cash
    $user = query("SELECT cash FROM users WHERE id=?", $user_id);
    $cash = $user[0]["cash"];
     
    $positions = [];
    $overall_total = 0;
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $stock_total = $row["shares"] * $stock["price"];
            $overall_total += $stock_total;
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"],
                "total" => $stock_total
            ];
        }
    }

    // render portfolio
    render("portfolio.php", [
        "title" => "Portfolio", 
        "positions" => $positions, 
        "cash" => $cash - $overall_total
    ]);

?>
