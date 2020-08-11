/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlength.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:23:22 by tmaarela          #+#    #+#             */
/*   Updated: 2020/02/13 15:55:36 by tmaarela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_numlength(long long num)
{
	int ret;

	ret = 1;
	if (num < 0)
		ret++;
	while (num / 10 != 0)
	{
		num /= 10;
		ret++;
	}
	return (ret);
}
