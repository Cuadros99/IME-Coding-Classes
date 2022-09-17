pergunta:- repeat,
write('Quer um restaurante no centro?'),nl,
write('1-Sim'),nl,
write('2-Nao'),nl,
write('3-Sair'),nl,
read(X),
processa(X),
X==3,!,write('Adeus').
processa(1):-assert(fact(restaurante_a)),!.
processa(2):-assert(fact(restaurante_b)),!.
processa(3):-!.
processa(_):-write('Opcao invalida!'),nl,nl.

