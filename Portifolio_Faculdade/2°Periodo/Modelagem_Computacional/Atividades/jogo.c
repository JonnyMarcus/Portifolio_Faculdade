/*
 * Atividade 05g - Simulacao: passeio na montanha russa 2D
 *
 * Compilar: gcc montanha_russa.c -o montanha_russa -lm
 * Executar: ./montanha_russa
 */
#include <stdio.h>
#include <math.h>

#define G 10.0     /* aceleracao da gravidade (m/s^2) */
#define TOL 0.10   /* erro aceito: 10% (o valor e "corrigido") */
#define FAIXA 0.30 /* faixa exibida ao jogador: +-30% */

/* Le um valor real positivo; devolve 0 se a entrada for invalida. */
static int ler_positivo(const char *msg, double *x)
{
    printf("%s", msg);
    if (scanf("%lf", x) != 1 || *x <= 0.0)
    {
        printf("Entrada invalida. Use um numero maior que zero.\n");
        return 0;
    }
    return 1;
}

/*
 * Uma jogada: mostra a faixa de +-30%, le o valor do jogador e confere.
 *  - dentro de 10% do correto -> usa o valor correto e segue (retorna 1)
 *  - fora de 10%              -> "fim de jogo!" (retorna 0)
 */
static int jogada(const char *pergunta, const char *unid, double correto,
                  const char *msg_menor, const char *msg_maior, double *usado)
{
    double v;

    printf("  Faixa possivel: %.2f a %.2f %s\n",
           correto * (1.0 - FAIXA), correto * (1.0 + FAIXA), unid);
    printf("  %s ", pergunta);
    if (scanf("%lf", &v) != 1)
    {
        printf("\n  Entrada invalida.\n");
        return 0;
    }
    printf("%.4f\n", v);

    if (fabs(v - correto) <= TOL * correto)
    {
        printf("  -> Dentro de 10%%: valor ajustado para %.3f %s.\n",
               correto, unid);
        *usado = correto;
        return 1;
    }
    printf("  -> FIM DE JOGO! %s\n", v < correto ? msg_menor : msg_maior);
    return 0;
}

int main(void)
{
    double M, V, H;
    double m1, m2, vA, vB, EB;  /* colisao e trecho A-B   */
    double mC, WCD, vD;         /* ajuste em B, freio C-D */
    double mF, KEH, vH, Ffinal; /* ajuste em F, freio H-I */
    double resp;

    printf("=== PASSEIO NA MONTANHA RUSSA 2D ===\n");
    printf("g = %.0f m/s^2\n\n", G);

    if (!ler_positivo("Massa M do carrinho (kg): ", &M))
        return 1;
    if (!ler_positivo("Velocidade V do carrinho (m/s): ", &V))
        return 1;
    if (!ler_positivo("Altura referencial H (m): ", &H))
        return 1;

    /* ---------- Colisao elastica em A ---------- */
    m1 = M;
    m2 = 1.25 * M;
    vA = 2.0 * m1 * V / (m1 + m2); /* velocidade do carrinho 2 */
    printf("\n[A] Colisao elastica: carrinho 2 (%.3f kg) sai com %.3f m/s\n",
           m2, vA);
    printf("    (carrinho 1 volta com %.3f m/s)\n",
           (m1 - m2) * V / (m1 + m2));

    /* ---------- Trecho A -> B ---------- */
    vB = sqrt(vA * vA + 2.0 * G * H);
    EB = 0.5 * m2 * vB * vB; /* energia mecanica total (h_B = 0) */
    printf("[B] Chegou na base com %.3f m/s | energia mecanica = %.3f J\n",
           vB, EB);

    /* ---------- Ajuste de massa em B (alvo: topo C, h = 5H/4) ---------- */
    mC = EB / (G * 5.0 * H / 4.0);
    printf("\n>> AJUSTE DE MASSA EM B (para chegar ao topo C com v = 0)\n");
    if (!jogada("Nova massa (kg):", "kg", mC,
                "Sobrou energia: decolou no topo C!",
                "Nao conseguiu alcancar o topo C!", &resp))
        return 0;
    mC = resp;

    /* ---------- Freio C -> D (alvo: topo E, h = 3H/4) ---------- */
    WCD = mC * G * (5.0 * H / 4.0 - 3.0 * H / 4.0); /* = mC*g*H/2 */
    vD = sqrt(2.0 * G * 3.0 * H / 4.0);
    printf("\n[C] No topo, v = 0. Energia a dissipar ate D deixa v_D = %.3f m/s\n",
           vD);
    printf(">> FREIO NO TRECHO C-D (energia dissipada pelo freio)\n");
    if (!jogada("Trabalho do freio (J):", "J", WCD,
                "Dissipou pouco: decolou no topo E!",
                "Dissipou demais: nao alcancou o topo E!", &resp))
        return 0;

    /* ---------- Ajuste de massa em F (alvo: topo G, h = H/2) ---------- */
    mF = mC * (3.0 * H / 4.0) / (H / 2.0);
    printf("\n[E] Topo com v = 0. Descendo ate F...\n");
    printf(">> AJUSTE DE MASSA EM F (para chegar ao topo G com v = 0)\n");
    if (!jogada("Nova massa (kg):", "kg", mF,
                "Sobrou energia: decolou no topo G!",
                "Nao conseguiu alcancar o topo G!", &resp))
        return 0;
    mF = resp;

    /* ---------- G -> H e freio H -> I ---------- */
    KEH = mF * G * (1.0 / 2.0 - 3.0 / 8.0) * H;
    vH = sqrt(2.0 * KEH / mF);
    Ffinal = KEH / (3.0 * H); /* trabalho = F * D_HI, D_HI = 3H */
    printf("\n[G] Topo com v = 0. Descida ate H: v_H = %.3f m/s (Ec = %.3f J)\n",
           vH, KEH);
    printf(">> FREIO FINAL H-I (distancia %.2f m)\n", 3.0 * H);
    if (!jogada("Forca de frenagem (N):", "N", Ffinal,
                "Freio fraco: passou do ponto I!",
                "Freio forte: parou antes do ponto I!", &resp))
        return 0;

    printf("\n*** PARABENS! O carrinho parou exatamente em I. ***\n");
    return 0;
}