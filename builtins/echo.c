#include "../includes/minishell.h"

void my_echo(t_token *lst)
{
    t_token *tmp;
    int     flag;

    tmp = lst;
    flag = 1;
    if (!tmp)
        return ;
    if (tmp->next)
    {
        tmp = tmp->next;
        if (ft_strcmp(tmp->value, "-n") == 0)
        {
            flag = 0;
            tmp = tmp->next;
        }
        while (tmp && tmp->type == WORD)
        {
            ft_putstr_fd(tmp->value, 1);
            tmp = tmp->next;
            if (tmp && tmp->type == WORD)
                write(1, " ", 1);
        }
        if (flag)
            write(1,"\n", 1);
    }
    else
        write(1, "\n", 1);
}