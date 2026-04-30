def produto_cartesiano(a, b):
    return {(x, y) for x in a for y in b}


def relacao_reflexiva(conjunto, relacao):
    return all((x, x) in relacao for x in conjunto)


def relacao_simetrica(relacao):
    return all((b, a) in relacao for (a, b) in relacao)


def relacao_transitiva(relacao):
    for (a, b) in relacao:
        for (c, d) in relacao:
            if b == c and (a, d) not in relacao:
                return False
    return True