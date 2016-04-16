var i = 0;
var tab = [];

if (document.cookie)
{
	tab = JSON.parse(document.cookie);
	for(let elem in tab)
	{
		if (tab[elem] && tab[elem] != "")
		{
			var todo = document.getElementById('ft_list');
			todoChild = document.createElement('div');
			todoChild.id = elem;
			i++;
			todoChild.innerHTML = tab[elem];
			todo.insertBefore(todoChild, todo.firstChild);
			document.getElementById(elem).addEventListener('click', function(){
				ft_remove(this.id);
			}, false);
		}
	}

}

function ft_prompt(){
	var input = prompt("Add to do list");
	if (input != "")
	{
		var todo = document.getElementById('ft_list');
		todoChild = document.createElement('div');
		todoChild.id = i;
		i++;
		todoChild.innerHTML = input;
		todo.insertBefore(todoChild, todo.firstChild);
		document.getElementById(i - 1).addEventListener('click', function(){
			ft_remove(this.id);
		}, false);
		tab.push(input);
		document.cookie = JSON.stringify(tab);
	}
}

function ft_remove(id){
	var check = confirm("Voulez vous supprimer ce to do ?");
	if (check == true)
	{
		var list = document.getElementById(id);
		list.remove();
		tab.splice(id, 1);
		document.cookie = JSON.stringify(tab);
		console.log(id);
	}
}
