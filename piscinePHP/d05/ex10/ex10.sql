SELECT film.titre AS 'Titre', film.resum AS 'Resume', film.annee_prod FROM film, genre WHERE film.id_genre=genre.id_genre AND genre.nom="erotic" ORDER BY annee_prod DESC;
