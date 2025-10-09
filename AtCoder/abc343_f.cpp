#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
/*
point update e contar ocorrencias do <segundo> menor
obviamente preciso do menor pra saber qual o proximo 

node { menor, segundomenor }

no merge

pair de menor1, segundomenor1
pair menor 2, segundo menor2
sorta e pega os dois primeiros, (fodase)
junto com a qntd de vezes q ele aparece

claim: sempre vai ser um desses 4 valores, pq se nao fosse haveriam mais 1 ou 2 menores do q
eu ja tenho no node, oq eh contradicao

se menor1 == menor2
    menor = menor1
    cnt = cntmenor1 + cntmenor2
senao
    if menor1 < menor2
        menor = menor1
        cnt = menor1
    else
        menor = menor2
        cnt = menor2

segundomenor = -1
    se segundomenor1 == -1
        segundomenor = segundomenor2
    se segundomenor2 == -1
        segundomenor = segundomenor1
    senao
    segundomenor1 < segundomenor2 e segundomenor1 > menor
    segundomenor2 < segundomenor1 e segundomenor1 > menor

*/
void dale() {
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}
