/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qudesvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:16:43 by qudesvig          #+#    #+#             */
/*   Updated: 2018/11/22 08:19:23 by qudesvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if (!alst || !del)
		return ;
	if ((*alst)->next != NULL)
		ft_lstdel(&((*alst)->next), del);
	del((*alst)->content, (*alst)->content_size);
	ft_memdel((void*)alst);
	*alst = NULL;
}
