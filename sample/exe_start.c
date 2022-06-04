#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <stdlib.h>

static char	*str_cutter(const char	*s, size_t start, size_t end)
{
	char	*ptr;
	size_t	i;
	size_t	len;

	i = 0;
	len = end - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static size_t	str_separate_count(const char *s, char c)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			ret++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (ret);
}

void	free_split_str(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	split_loop(char **split, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	start = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i = split_loop_check(s, c, i);
		else if (s[i] != c)
		{
			start = i;
			while (s[i] != c && i != ft_strlen(s))
				i++;
			split[j] = str_cutter(s, start, i);
			if (!split[j])
				return (-1);
			j++;
		}
	}
	split[j] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (str_separate_count(s, c) + 1));
	if (!split)
		return (NULL);
	if (split_loop(split, s, c) == -1)
		free_split_str(split);
	return (split);
}

char *ft_strjoin(char *s1, char *s2)
{
	size_t total_len = strlen(s1) + strlen(s2);
	char *ret = malloc(sizeof(char) * (total_len + 1));
	size_t i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	size_t j = 0;
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return ret;
}

int main(int argc, char **argv, char **envp)
{
	while (1)
	{
		char *str = readline("yeah!> ");
		add_history(str);
		str = ft_strjoin("/bin/", str);
		char *cmd[] = {str, NULL};

		int pid = fork();
		if (pid == 0)
		{
			execve(cmd[0], cmd, NULL);
			exit(127);
		}
		else
		{
			int sts;
			wait(&sts);
			if (WEXITSTATUS(sts) == 127)
				printf("command not found:%s\n", str);
		}
	}
	return 0;
}
