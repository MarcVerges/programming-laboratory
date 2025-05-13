# -*- coding: utf-8 -*-

def llegirFitxer(nomFitxer):
    fitxer = open(nomFitxer, "rt")
    comandes = dict()
    for linia in fitxer:
        paraules = linia.split()
        comandes[paraules[0]] = paraules[1:]
    return comandes

def modificaClient(comandes, nomClient, novesComandes):
    if nomClient in comandes:
        comandes[nomClient] = comandes[nomClient] + novesComandes
    else:
        comandes[nomClient] = novesComandes

def eliminaComanda(comandes, nomClient, codiComanda):
    if nomClient in comandes:
        if codiComanda in comandes[nomClient]:
            comandes[nomClient].remove(codiComanda)
        else:
            print ('Error. Comanda no existent')
    else:
        print ('Error. Client no existent')

def nComandes(comandes):
    nComandesClient = [[k, len(v)] for k,v in sorted(comandes.items())]
    return nComandesClient


def nTotalComandes(comandes):
    nComandesClient = nComandes(comandes)
    return sum (nc[1] for nc in nComandesClient)
    
def clientsMultiplesComandes(comandes):
    nComandesClient = nComandes(comandes)
    clientsMultiples = [c[0] for c in nComandesClient if c[1] > 1]
    return clientsMultiples
 
def nomsComandes(comandes):
    noms = [c[0] for c in comandes]
    return noms

