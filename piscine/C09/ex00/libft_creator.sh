# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vburton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/17 11:08:36 by vburton           #+#    #+#              #
#    Updated: 2022/09/18 10:36:34 by vburton          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

gcc -c *.c 
ar rc libft.a *.o
ranlib libft.a
