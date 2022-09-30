/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:41:41 by lmedeiro          #+#    #+#             */
/*   Updated: 2022/09/29 21:02:44 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{//Começamos vendo se o int passado no parâmetro é -2147483648. O número 2147483648 é o maior número 
	//que uma variável int pode conter. Quando um sinal negativo é colocado na frente dele, nossa função 
	//não é capaz de lidar com isso. Então, verificamos se uma versão negativa foi dado e, em caso afirmativo, 
	//nós o devolvemos imediatamente.
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
		//Se -2147483648 não tiver sido fornecido, verificamos se outro número negativo foi fornecido. Se o número 
	//for negativo, imediatamente use ft_putchar('-') para exibir o sinal de menos na saída padrão. Em seguida, 
	//chamamos ft_putnbr novamente em uma versão negativa da variável n, tornando-a um número positivo e executamos 
	//a função novamente desde o início. Se o nosso número dado não for negativo, passamos para o próximo else if.
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
		//Agora verificamos se o número é maior ou igual a 10. Se for, começamos a decompor o número recursivamente 
	//para cada dígito individual, onde o converteremos em um caractere. Semelhante à nossa divisão recursivamente 
	//em nosso ft_itoa,  mais uma vez vamos usar uma divisão por 10 e um módulo por 10. A divisão por 10 nos levará 
	//adiante na recursão até que finalmente alcancemos o primeiro número em nosso int. Se você olhar para o módulo 10, 
	//usamos a + '0' para converter o número em um valor char. Embora isso pareça que será colocado na saída padrão 
	//imediatamente, na verdade acontecerá por último, pois será a última coisa a acontecer quando retrocedermos em nossa recursão.
    //Se você está tendo dificuldade em entender a recuso, você deve escrever os passos que esta função irá realizar 
	//em um pedaço de papel. Como o ft_itoa, ele deve criar uma imagem que se pareça com uma árvore binária. No final 
	//de nossa desconstrução de dígitos, adicionaremos '0' ao int para torná-lo um valor de caractere. Usaremos ft_putchar 
	//neste dígito para exibi-lo na saída padrão e, em seguida, retornaremos à nossa recursão até que cada dígito individual tenha sido exibido.
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd); //aqui é o fator limitante/base
}
