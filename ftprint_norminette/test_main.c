/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharman <moharman@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:37:36 by moharman          #+#    #+#             */
/*   Updated: 2025/10/02 16:37:39 by moharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stddef.h>
#include <stdarg.h> // Nécessaire pour va_copy dans la fonction de test

// --- Prototype de la fonction vft_printf (Définie dans ft_printf.c) ---
// Note: Ceci doit être ajouté à ft_printf.h: int ft_vprintf(const char *f, va_list args);
int ft_vprintf(const char *format, va_list args); 

// Fonction de test qui utilise va_copy pour appeler ft_vprintf et vprintf (STD)
void run_test(const char *format, ...)
{
    va_list args_originale;
    va_list ft_args;
    va_list std_args;
    int ft_ret;
    int std_ret;
    
    // 1. Initialiser la liste originale
    va_start(args_originale, format);
    
    // 2. Appel ft_printf (via vprintf)
    va_copy(ft_args, args_originale);
    printf("FT: |");
    fflush(stdout); 
    ft_ret = ft_vprintf(format, ft_args); // Utilisation de vft_printf pour tester
    va_end(ft_args);
    printf("| (RET: %d)\n", ft_ret);

    // 3. Appel vprintf (STD)
    va_copy(std_args, args_originale);
    printf("STD: |");
    std_ret = vprintf(format, std_args);
    va_end(std_args);
    printf("| (RET: %d)\n", std_ret);
    
    va_end(args_originale);
    
    // Comparaison du succès
    if (ft_ret == std_ret)
        printf("-> ✅ Succès (RETURS IDENTIQUES)\n");
    else
        printf("-> ❌ Échec (FT_ret: %d | STD_ret: %d)\n", ft_ret, std_ret);
    printf("==================================================\n");
}

int main()
{
    // Variables pour les tests (null_s_ptr doit être défini dans le main ou ailleurs)
    char *null_s_ptr = (char *)NULL; 
    int num_neg = -42;
    unsigned int u_max = 4294967295U;
    unsigned char hex_val = 255;
    
    printf("\n==================================================\n");
    printf("=== DÉBUT DES TESTS ft_printf (Partie Obligatoire) ===\n");
    printf("==================================================\n\n");
    
    // TEST 1 : Caractère simple (%c)
    run_test("Test 1: [%c]", 'X');

    // TEST 2 : Chaîne (%s) et NULL (Correction du type par cast)
    run_test("Test 2: [%s]", null_s_ptr);

    // TEST 3 : Entier (%d)
    run_test("Test 3: [%d]", num_neg);

    // TEST 4 : Entier INT_MIN (Sécurité)
    run_test("Test 4: [INT_MIN] %d", INT_MIN);
    
    // TEST 5 : Unsigned Int (%u)
    run_test("Test 5: [Unsigned] %u", u_max);

    // TEST 6 : Hexa minuscule (%x)
    run_test("Test 6: [Hexa min] %x", hex_val);

    // TEST 7 : Hexa majuscule (%X)
    run_test("Test 7: [Hexa maj] %X", hex_val);

    printf("=== FIN DES TESTS ===\n");
    return 0;
}