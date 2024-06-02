import matplotlib.pyplot as plt
 
pos = [1, 2, 3, 4, 5, 6, 7, 8]
vals = [0.000629, 0.000570, 0.005592, 0.005554, 0.06, 0.059, 0.63, 0.61]
labels = ['mil','', 'dez mil','', 'cem mil','', 'milhao','']
plt.bar(pos, vals, tick_label = labels,
        width = 0.1, color=['red', 'blue'])
plt.xlabel('entradas')
plt.ylabel('tempo(s)')
plt.title('Tempo de Execução')
plt.show()