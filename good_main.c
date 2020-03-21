
int	main(int ac, char **av)
{
	int			i;
	int 		nbr;
	t_lista 	*first;
	t_lista 	*current;
	t_lista 	*new;

	i = 1;
	current = NULL;
	first = NULL;
	if (ac > 1)
	{
		while (ac-- > 1)
		{
			nbr = atoi(av[i]);
			if (i == 1)
			{
				first = make_structure();
				current = first;
			}
			else
			{
				new = make_structure();
				current->next = new;
				current = new;
			}
			fill_structure(current, nbr);			
			current->next = NULL;
			i++;
		}		
	}
	else
		ERROR;
	// display_list(first);
	printf("\n");
	display_list(first);
	first = sa(first);	
	display_list(first);
	// while (1)
	// {
		
	// }
	return (0);
}