CREATE TABLE  ft_table(id int NOT NULL AUTO_INCREMENT, login CHAR(8) NOT NULL DEFAULT 'toto', groupe ENUM('staff', 'student', 'other') NOT NULL, date_de_creation date NOT NULL, PRIMARY KEY(id));
