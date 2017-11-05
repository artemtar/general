with  open("trainingData.data", 'r') as file_data:
    count = sum(1 for line in file_data)
    part = count / 10