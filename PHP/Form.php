<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>PHP Form</title>
    <style>
        *{
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
            box-sizing: border-box;
            text-decoration: none;
        }
        body{
            background-color: #dfe7ef;
        }
        .container{
            background-color: white;
            width: inherit;
            margin: 20px;
            padding: 20px;
        }
        .container h1{
            text-align: center;
        }
        input,.dropd{
            border: 2px solid #dfe7ef;
            border-radius: 6px;
            outline: none;
            padding: 0 15px;
            font-size: 17px;
            margin-right: 10px;
        }
        .fields,.fields1{
            display:flex;
            height: 45px;
            margin-bottom: 15px;
            margin-right: 10px;
            margin-left: 31%;
        }
        .fields1 input{
            width:470px;
        }
        .btn1,.btn2,.container a{
            font-size: 17px;
            font-weight: 500;
            background: #000716;
            color: white;
            padding: 8px 16px;
            border-radius: 6px;
            border: 2px solid #000716;
            cursor: pointer;
            transition: all 0.3s ease;
        }
        .btn1{
            margin-left: 31%;
        }
        .btn:hover{
            background-color: white;
            color: #000716;
        }
        .dropd{
            display: flex;
            padding-right: 36px;
            font-size: 19px;
            background-color: white;
            cursor: pointer;
        }
        .dropd1{
            display: flex;
            padding-right: 35px;
            font-size: 19px;
            background-color: white;
            cursor: pointer;
        }
        #dtime{
            padding-left: 55px;
        }
        @media(max-width:1080px){
            .fields,.fields1{
                flex-direction: column;
                margin: 0;
                font-size: 19px;   
                height: fit-content;
                margin-left: 0;
            }
            input{
                padding: 0 10px;
                font-size: 17px;
                height: 45px;
                margin-bottom: 20px;
            }
            .fields1 input{
                width:auto;
            }
            .btn1{
                margin-left: 0;
            }
            .dropd,.dropd1{
                margin-left: 0%;
                padding: 0 10px;
                font-size: 17px;
                height: 45px;
                margin-bottom: 20px;
                width: auto;
            }
            input[type="date"]::before {
	            color: #000716;
	            content: attr(placeholder);
            }
            input[type="date"]:focus::before,input[type="date"]:valid::before{
	            content: "" !important;
            }
            #dtime{
                padding-left: 10px;
            }
            input[type="time"]::before {
	            color: #000716;
	            content: attr(placeholder);
            }
            input[type="time"]:focus::before,input[type="time"]:valid::before{
	            content: "" !important;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <?php
            echo "<h1>Form Submission</h1>";
        ?>
    </div>
    <div class="container">
        <?php
            if(isset($_POST['FormSubmited']))
            {
                echo "<h1>Form Submitted Sucessfully...</h1></div>";
                echo "<div class='container'><h2>Here's what we received...</h2><br>";
                echo "Name: &nbsp;&nbsp;".$_POST['FirstName']."&nbsp;".$_POST['LastName']."<br><br>";
                echo "Email id: &nbsp;".$_POST['Mail']."<br><br>";
                echo "Phone Number: &nbsp;".$_POST['Phone']."<br><br>";
                echo "CU Reg No: &nbsp;".$_POST['RegNo']."<br><br>";
                echo "CU Roll No: &nbsp;".$_POST['RollNo']."<br><br>";
                echo "Stream: &nbsp;".$_POST['Stream']."<br><br>";
                echo "Semister: &nbsp;".$_POST['Semister']."<br><br>";
                echo "Subject Code: &nbsp;".$_POST['Subject']."<br><br>";
                echo "Date & Time: &nbsp;".$_POST['Date']."&nbsp;&nbsp;".$_POST['Time']."<br><br><br>";   
                echo "<a href='Form.php'>Go Back</a><br><br>";
            }
            else
            {
                echo "<form action='Form.php' method='post' autocomplete='off'>";
                echo "<div class='fields'><input type='text' name='FirstName' placeholder='First Name' required >";
                echo "<input type='text' name='LastName' placeholder='Last Name' required ></div>";
                echo "<div class='fields1'><input type='email' name='Mail' placeholder='Email Id' required ></div>";
                echo "<div class='fields1'><input type='tel' name='Phone' placeholder='Phone Number' required ></div>";
                echo "<div class='fields1'><input type='text' name='RegNo' placeholder='CU Reg No: [ XXX-XXXX-XXXX-XX ]' required ></div>";
                echo "<div class='fields1'><input type='text' name='RollNo' placeholder='CU Roll No: [ XXXXXX-XX-XXXX ]' required ></div>";
                echo "<div class='fields'><select name='Stream' class='dropd' required>
                    <option value=''>Select the Stream</option>
                    <option value='B.A'>B.A</option>
                    <option value='B.Com'>B.Com</option>
                    <option value='B.Sc'>B.Sc</option></select>";
                echo "<select name='Semister' class='dropd' required>
                    <option value=''>Select the Semister</option>
                    <option value='Sem-1'>Semister 1</option>
                    <option value='Sem-2'>Semister 2</option>
                    <option value='Sem-3'>Semister 3</option>
                    <option value='Sem-4'>Semister 4</option>
                    <option value='Sem-5'>Semister 5</option>
                    <option value='Sem-6'>Semister 6</option></select></div>";
                echo "<div class='fields1'><input type='text' name='Subject' placeholder='Subject Code' required ></div>";
                echo "<div class='fields'><input placeholder='Date' type='date' name='Date' class='dropd1' required></input>";
                echo "<input placeholder='Time' type='time' name='Time' class='dropd' id='dtime' required></input></div>";
                echo "<input type='hidden' name='FormSubmited' Svalue='1'>";
                echo "<input class='btn1' type='submit' value='Submit'>";
                echo "<input class='btn2' type='reset' value='Reset'>";
                echo "</form>";
            }
        ?>
    </div>
</body>
</html>