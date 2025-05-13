# -*- coding: utf-8 -*-

def llegirFitxer(nomFitxer):
    list = []
    fitxer = open(nomFitxer,'rt')
    for linia in fitxer:
        paraules = linia.split()
        list.append([paraules[0],paraules[1:]])
    return list

def modificaClient(comandes, nomClient, novesComandes):
    noms = [c[0] for c in comandes]
    
    if nomClient in noms:
        posicio = comandes.index(nomClient)
        comandes[posicio][1] = comandes[posicio][1] + novesComandes
    
    else:
        comandes.append([nomClient,novesComandes])


def eliminaComanda(comandes, nomClient, codiComanda):
    noms = [c[0] for c in comandes]
    
    if nomClient in noms:
        posicio = comandes.index(nomClient)
        if codiComanda in comandes[posicio][1]:
            comandes[posicio][1].remove(codiComanda)
        else:
            print ("Error. Comanda no existent")
    else:
        print ("Error. Comanda no existent")
   

def nComandes(comandes):
    nComandesClient = [[c[0], len(c[1])] for c in comandes]
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
