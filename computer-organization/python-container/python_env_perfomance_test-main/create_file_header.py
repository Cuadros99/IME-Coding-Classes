import csv
with open ('./results.csv', 'a+') as file:
    writer = csv.writer(file)
    header = ['function name', 'avg time', 'std dev'] 
    writer.writerow(header)

