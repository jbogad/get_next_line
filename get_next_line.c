/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaboga-d <jaboga-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:52:09 by marvin            #+#    #+#             */
/*   Updated: 2025/02/26 11:01:38 by jaboga-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buffer(int fd, char *buffer)
{
	char	*temp_buffer;
	int		bytes_read;

	bytes_read = 1;
	if (!buffer)
		buffer = NULL;
	temp_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (free(buffer), NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(temp_buffer), free(buffer), NULL);
		temp_buffer[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, temp_buffer);
		if (ft_strchr(temp_buffer, '\n'))
			break ;
	}
	free(temp_buffer);
	return (buffer);
}

static char	*sac_line(char *acu_buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!acu_buffer)
		return (NULL);
	while (acu_buffer[i] && acu_buffer[i] != '\n')
	{
		i++;
	}
	line = ft_substr(acu_buffer, 0, i + 1);
	return (line);
}

static char	*mod_buffer(char *acu_buffer)
{
	int		i;
	char	*new_buffer;

	i = 0;
	if (!acu_buffer)
	{
		free(acu_buffer);
		acu_buffer = NULL;
		return (NULL);
	}
	while (acu_buffer[i] != '\n' && acu_buffer[i] != '\0')
		i++;
	new_buffer = ft_substr(acu_buffer, i + 1, ft_strlen(acu_buffer) - i);
	if (!new_buffer)
	{
		free(acu_buffer);
		return (NULL);
	}
	free(acu_buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer_read;
	char		*line;

	buffer_read = read_buffer(fd, buffer_read);
	if (!buffer_read)
		return (NULL);
	line = sac_line(buffer_read);
	if (!line)
		return (free(buffer_read), buffer_read = NULL);
	buffer_read = mod_buffer(buffer_read);
	if (line && *line == '\0')
	{
		free(line);
		free(buffer_read);
		buffer_read = NULL;
		return (NULL);
	}
	return (line);
}

// int main(int argc, char **argv)
// {
//     int fd;
//     char *line;

//     if (argc != 2)
//     {
//         printf("Uso: %s <archivo>\n", argv[0]);
//         return (1);
//     }

//     fd = open(argv[1], O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error al abrir el archivo");
//         return (1);
//     }

//     while ((line = get_next_line(fd)))
//     {
//         printf("%s", line);
//         free(line);
//     }

//     close(fd);
//     return (0);
// }