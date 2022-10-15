<?php
    include('server.php');
?>
<html>
    <head>
        <title>Registration System</title>
        <link rel="stylesheet" href="style.css">
    </head>
    <body>
        <div class="header">
            <h2>Login</h2>
        </div>
        <form action="login.php" method="post">
            <?php include('errors.php'); ?>
            <div class="input_group">
                <label>Username</label>
                <input type="text" name="username">
            </div>
            <div class="input_group">
                <label>Password</label>
                <input type="password" name="password">
            </div>
            <div class="input_group">
                <button type="submit" class="btn" name="login_user">Login</button>
            </div>
            <p>Not yet a member? <a href="register.php">Sign up</a></p>
        </form>
    </body>
</html>