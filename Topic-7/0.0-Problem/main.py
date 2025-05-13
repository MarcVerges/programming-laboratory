# -*- coding: utf-8 -*-


if __name__ == "__main__":
    """ Aquí aneu posant les diferents proves"""
    grade = 0

    ''' Primer amb llistes '''
    from llegirComandes_list import *

    # Part 1
    comandes = llegirFitxer("comandes.txt")
    res = comandes
    print("Comandes: "+ str(comandes))

    sol = [['client1', ['101', '102', '103']], ['client2', ['201']], ['client3', ['301', '302']], ['client4', ['401', '402', '403', '404']], ['client5', ['501', '502', '503', '504', '505', '506']], ['client6', ['601']], ['client7', ['701', '702', '703']], ['client8', ['801', '802', '803', '804']], ['client9', ['901']]]
    if res == sol:
        grade += 1.0   
        print(f"Comment ==> Funcio llegirFitxer() per llistes correcte")
        print ("Grade :=>>", grade)
    else:
        print(f"Comment ==> Error Funcio llegirFitxer() amb llistes")

    print('')

    # Part 2
    modificaClient(comandes, 'client1',  ['501', '502', '503', '504', '505', '506'])
    modificaClient(comandes, 'client10', ['111'])
    res = comandes
    print("Comandes: "+ str(comandes))

    sol = [['client1', ['101', '102', '103', '501', '502', '503', '504', '505', '506']], ['client2', ['201']], ['client3', ['301', '302']], ['client4', ['401', '402', '403', '404']], ['client5', ['501', '502', '503', '504', '505', '506']], ['client6', ['601']], ['client7', ['701', '702', '703']], ['client8', ['801', '802', '803', '804']], ['client9', ['901']], ['client10', ['111']]]
    if res == sol:
        grade += 1.0   
        print(f"Comment ==> Funcio modificaClient() per llistes correcte")
        print ("Grade :=>>", grade)
    else:
        print(f"Comment ==> Error Funcio modificaClient() amb llistes")

    print('')

    # Part 3
    eliminaComanda(comandes, 'client10', '111')
    eliminaComanda(comandes, 'client1' , '501')
    eliminaComanda(comandes, 'client10', '111')
    eliminaComanda(comandes, 'client11', '111')
    print("Comandes: "+ str(comandes))
    res = comandes

    sol = [['client1', ['101', '102', '103', '502', '503', '504', '505', '506']], ['client2', ['201']], ['client3', ['301', '302']], ['client4', ['401', '402', '403', '404']], ['client5', ['501', '502', '503', '504', '505', '506']], ['client6', ['601']], ['client7', ['701', '702', '703']], ['client8', ['801', '802', '803', '804']], ['client9', ['901']], ['client10', []]]
    if res == sol:
        grade += 1.0   
        print(f"Comment ==> Funcio modificaClient() per llistes correcte")
        print ("Grade :=>>", grade)
    else:
        print(f"Comment ==> Error Funcio modificaClient() amb llistes")

    print('')

    # Part 4
    nC = nComandes(comandes)
    res = nC
    print("Numero de Comandes per client: "+ str(nC))
    ntC = nTotalComandes(comandes)
    res2 = ntC
    print("Numero total de Comandes: "+ str(ntC))
    cmC = clientsMultiplesComandes(comandes)
    res3 = cmC
    print("Clients amb multiples comandes: "+ str(cmC))

    sol = [['client1', 8], ['client2', 1], ['client3', 2], ['client4', 4], ['client5', 6], ['client6', 1], ['client7', 3], ['client8', 4], ['client9', 1], ['client10', 0]]
    sol2 = 30
    sol3 = ['client1', 'client3', 'client4', 'client5', 'client7', 'client8']
    if (res == sol) and (res2 == sol2) and (res3 == sol3):
        grade += 2.0   
        print(f"Comment ==> Funcio modificaClient() per llistes correcte")
        print ("Grade :=>>", grade)
    else:
        print(f"Comment ==> Error Funcio modificaClient() amb llistes")

    print('')
    

    ''' Ara amb Diccionaris '''
    from llegirComandes_dict import *

    # Part 1
    comandes = llegirFitxer("comandes.txt")
    res = comandes
    print("Comandes: "+ str(comandes))

    sol = {'client1': ['101', '102', '103'], 'client2': ['201'], 'client3': ['301', '302'], 'client4': ['401', '402', '403', '404'], 'client5': ['501', '502', '503', '504', '505', '506'], 'client6': ['601'], 'client7': ['701', '702', '703'], 'client8': ['801', '802', '803', '804'], 'client9': ['901']}
    if res == sol:
        grade += 1.0   
        print(f"Comment ==> Funcio llegirFitxer() per diccionaris correcte")
        print ("Grade :=>>", grade)
    else:
        print(f"Comment ==> Error Funcio llegirFitxer() amb diccionaris")

    print('')

    # Part 2
    modificaClient(comandes, 'client1',  ['501', '502', '503', '504', '505', '506'])
    modificaClient(comandes, 'client10', ['111'])
    res = comandes
    print("Comandes: "+ str(comandes))

    sol = {'client1': ['101', '102', '103', '501', '502', '503', '504', '505', '506'], 'client2': ['201'], 'client3': ['301', '302'], 'client4': ['401', '402', '403', '404'], 'client5': ['501', '502', '503', '504', '505', '506'], 'client6': ['601'], 'client7': ['701', '702', '703'], 'client8': ['801', '802', '803', '804'], 'client9': ['901'], 'client10': ['111']}
    if res == sol:
        grade += 1.0   
        print(f"Comment ==> Funcio modificaClient() per diccionaris correcte")
        print ("Grade :=>>", grade)
    else:
        print(f"Comment ==> Error Funcio modificaClient() amb diccionaris")

    print('')

    # Part 3
    eliminaComanda(comandes, 'client10', '111')
    eliminaComanda(comandes, 'client1' , '501')
    eliminaComanda(comandes, 'client10', '111')
    eliminaComanda(comandes, 'client11', '111')
    print("Comandes: "+ str(comandes))
    res = comandes

    sol = {'client1': ['101', '102', '103', '502', '503', '504', '505', '506'], 'client2': ['201'], 'client3': ['301', '302'], 'client4': ['401', '402', '403', '404'], 'client5': ['501', '502', '503', '504', '505', '506'], 'client6': ['601'], 'client7': ['701', '702', '703'], 'client8': ['801', '802', '803', '804'], 'client9': ['901'], 'client10': []}
    if res == sol:
        grade += 1.0   
        print(f"Comment ==> Funcio modificaClient() per llistes diccionaris")
        print ("Grade :=>>", grade)
    else:
        print(f"Comment ==> Error Funcio modificaClient() amb diccionaris")

    print('')

    # Part 4
    nC = nComandes(comandes)
    res = nC
    print("Numero de Comandes per client: "+ str(nC))
    ntC = nTotalComandes(comandes)
    res2 = ntC
    print("Numero total de Comandes: "+ str(ntC))
    cmC = clientsMultiplesComandes(comandes)
    res3 = cmC
    print("Clients amb multiples comandes: "+ str(cmC))

    sol = {'client1': 8, 'client2': 1, 'client3': 2, 'client4': 4, 'client5': 6, 'client6': 1, 'client7': 3, 'client8': 4, 'client9': 1, 'client10': 0}
    sol2 = 30
    sol3 = {'client1': 8, 'client3': 2, 'client4': 4, 'client5': 6, 'client7': 3, 'client8': 4}
    if (res == sol) and (res2 == sol2) and (res3 == sol3):
        grade += 2.0   
        print(f"Comment ==> Funcio modificaClient() per diccionaris correcte")
        print ("Grade :=>>", grade)
    else:
        print(f"Comment ==> Error Funcio modificaClient() amb diccionaris")

    print('')


    ''' END '''
    print ("Grade :=>>", grade)
