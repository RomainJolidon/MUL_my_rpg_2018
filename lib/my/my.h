/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/
#ifndef SECU_MY_H
#define SECU_MY_H
#include <stdarg.h>

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_show_word_array(char * const *tab);
char *my_strdup(char const *src);
int swap_if_needed(int *nb1, int *nb2);
void put_limit_n(void);
int invert_sign(int count_n, int result);
int sum_stdarg(int i, int nb, ...);
int disp_stdarg(char *s, ...);
int my_printf(char *str, ...);
int check_flag(char flag, va_list ap);
int check_flag_2(char flag, va_list ap);
void my_print_printable(char *str);
int my_put_nbr_base(int nb, char *base);
int my_put_unbr_base(unsigned int nb, char *base);
char *int_to_str(int nb);
int my_put_unbr(unsigned int nb);
int my_show_int_array(int *tab, int size);
char *my_memset(char *str, int nb);

#endif
