#include "../minishell.h"

int check_token(t_token *token, t_kind kind, char *str)
{
	if (token->kind != kind)
		return 0;
	if (str != NULL && ft_strncmp(token->str, str, token->len) != 0)
		return 0;
	return 1;
}

void node_add_str(t_node *node, char *str)
{
	while (node->next)
		node = node->next;
	t_node *new_node = ft_calloc(1, sizeof(t_node));
	new_node->str = str;
	node->next = new_node;
}

void new_node(t_node *node, t_node *cmds, t_node *red_in, t_node *red_out)
{
	while (node->next)
		node = node->next;
	t_node *new_node = ft_calloc(1, sizeof(t_node));
	new_node->cmds = cmds;
	new_node->red_in = red_in;
	new_node->red_out = red_out;
	node->next = new_node;
}

t_node *parser(t_token *token)
{
	t_node node;//lexerの時同様nodeの先頭を番兵として持ってnextを渡す前提にする
	node.next = NULL;

	/*以下の3つをnew_nodeで繋ぐ*/
	t_node cmds;
	t_node red_in;
	t_node red_out;
	cmds.next = NULL;
	red_in.next = NULL;
	red_out.next = NULL;

	while (check_token(token, END, NULL) == 0)
	{
		if (check_token(token, WORD, NULL) == 1)
		{
			char *str = ft_strndup(token->str, token->len);
			node_add_str(&cmds, str);
		}
		if (check_token(token, OPE, "<") == 1)
		{
			token = token->next;
			if (check_token(token, END, NULL) == 1)
				continue ;
			char *str = ft_strndup(token->str, token->len);
			node_add_str(&red_in, str);
		}
		if (check_token(token, OPE, ">") == 1)
		{
			token = token->next;
			if (check_token(token, END, NULL) == 1)
				continue ;
			char *str = ft_strndup(token->str, token->len);
			node_add_str(&red_out, str);
		}
		if (check_token(token, OPE, "|") == 1)
		{
			new_node(&node, cmds.next, red_in.next, red_out.next);
			cmds.next = NULL;
			red_in.next = NULL;
			red_out.next = NULL;
		}
		token = token->next;
	}
	new_node(&node, cmds.next, red_in.next, red_out.next);
	return node.next;
}
//後でstart_parserに分割する予定
