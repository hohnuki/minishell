#include "../minishell.h"

size_t get_ope_len(char *str)
{
	const char *key[] = {"|", "<<", "<", ">", ">>", NULL};
	size_t i = 0;
	while (key[i])
	{
		if (ft_strncmp(str, key[i], ft_strlen(key[i])))
			return ft_strlen(key[i]);
		i++;
	}
	return 0;
}

size_t get_word_len(char *str) {
    size_t len = 0;
    while (str[len])
    {
	    if (str[len] == ' ')
		    break ;
	    len++;
    }
    return len;
}

void new_token(t_token *token, t_kind kind, char *str, size_t len)
{
	while (token->next)//new_tokenが呼ばれるたびに一つ進める
		token = token->next;
	t_token *new_token = ft_calloc(1, sizeof(t_token));
	new_token->str = str;
	new_token->kind = kind;
	new_token->len = len;
	token->next = new_token;
}


t_token *lexer(char *str)
{
	t_token token;//番兵を作成してnextをmainに戻す予定
	//tokenに関してはアドレスを動かすのはlexer内のみにする
	token.next = NULL;

	while (*str)
	{
		while (*str == ' ')
			str++;
		/* fprintf(stderr, "%s\n", str);//なぜか1しかインクリメントされない */
		size_t ope_len = get_ope_len(str);
		/* fprintf(stderr, "%zu\n", ope_len); */
		if (ope_len > 0)//judge ope
		{
			new_token(&token, OPE, str, ope_len);
			str = str + ope_len;//strを進める
			continue ;
		}

		size_t word_len = get_word_len(str);
		if (word_len > 0)//judge word
		{
			new_token(&token, WORD, str, word_len);
			str = str + word_len;//同上
			continue ;
		}
	}
	new_token(&token, END, str, 0);//!(OPE || WORD) == END
	return token.next;
}
