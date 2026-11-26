/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharbon <dcharbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 23:48:00 by dcharbon          #+#    #+#             */
/*   Updated: 2026/11/26 00:14:08 by dcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_app	app;

	app_init(&app);
	if (!parse_arguments(&app, argc, argv))
	{
		write(2, "Error\n", 6);
		app_cleanup(&app);
		return (1);
	}
	app_cleanup(&app);
	return (0);
}
// Init de la struct app
// Verification que la fonctionne. En cas d' echec, affichage de "error", puis clean de app et retour (1). ECHEC
// sinon clean de app apres operations et retour(0). Move along citizen.
