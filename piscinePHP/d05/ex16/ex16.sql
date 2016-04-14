SELECT COUNT(date) AS 'films' FROM historique_membre WHERE date BETWEEN '1998-09-22' AND '1998-10-01' OR (MONTH(date)=12 AND DAY(date)=24);
