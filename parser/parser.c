#include "../minishell.h"



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
	
	return node.next;
}
