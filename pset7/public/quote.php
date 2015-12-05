<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Quote"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $symbol = $_POST["symbol"];
        
        // validate
        if(empty($symbol))
            apologize("No symbol provided");
            
        // lookup stock
        $stock = lookup($symbol);
        
        // check if we found a stock item
        if($stock === false)
            apologize("Symbol not found");
        
        // render result page
        render("quote_price.php", $stock);
    }

?>
