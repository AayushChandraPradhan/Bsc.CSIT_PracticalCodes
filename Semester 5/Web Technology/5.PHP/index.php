<!DOCTYPE html>
<html>
<head>
    <title>PHP CRUD Operations</title>
    <style>
        table {
            border-collapse: collapse;
            width: 100%;
        }
        th, td {
            border: 1px solid black;
            padding: 8px;
            text-align: left;
        }
        th {
            background-color: #f2f2f2;
        }
    </style>
</head>
<body>
    <h2>Create Student</h2>
    <form action="create.php" method="POST">
        Name: <input type="text" name="name" required><br>
        Branch: <input type="text" name="branch" required><br>
        CGPA: <input type="number" step="0.01" name="cgpa" required><br>
        <input type="submit" value="Create">
    </form>

    <h2>Students List</h2>
    <?php
    require 'read.php';
    ?>
</body>
</html>
