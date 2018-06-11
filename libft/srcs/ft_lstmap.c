/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 17:01:14 by aanzieu           #+#    #+#             */
/*   Updated: 2018/05/14 13:04:14 by aanzieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*p_tmp;
	t_list	*p_elem;

	if (!lst || !f)
		return (NULL);
	p_elem = f(lst);
	if ((new = ft_lstnew(p_elem->content, p_elem->content_size)))
	{
		p_tmp = new;
		lst = lst->next;
		while (lst)
		{
			p_elem = f(lst);
			if (!(p_tmp->next = ft_lstnew(p_elem->content,
			p_elem->content_size)))
				return (NULL);
			p_tmp = p_tmp->next;
			lst = lst->next;
		}
	}
	return (new);
}
