<?php

    // configuration
    require("../includes/config.php"); 

    // current user ID
    $user_id = $_SESSION["id"];

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("reset_form.php", ["title" => "Reset password"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $password = $_POST["password"];
    
        // validate password 
        if (empty($password))
            apologize("An empty password is not allowed.");

        query("UPDATE users SET hash = ? WHERE id = ?", crypt($password), $user_id);
        
        redirect("index.php");
    }

?>
