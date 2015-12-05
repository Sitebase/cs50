<?php

    // configuration
    require("../includes/config.php"); 

    // current user ID
    $user_id = $_SESSION["id"];

    // get stock portfolio
    $rows = query("SELECT * FROM history WHERE user_id=?", $user_id);
    $events = [];
    foreach ($rows as $row)
    {
        $events[] = [
            "transaction" => $row["transaction"],
            "date" => date("m/d/y, h:ma", strtotime($row["datetime"])),
            "symbol" => $row["symbol"],
            "shares" => $row["shares"],
            "price" => round($row["price"], 2)
        ];
    }

    // render portfolio
    render("history.php", [
        "title" => "History", 
        "history" => $events
    ]);

?>
