# Step 1: Extract the data from the dictionary
medals_data = [
    {"Nation": "Canada", "Gold": 2, "Silver": 0, "Bronze": 2},
    {"Nation": "OAR", "Gold": 1, "Silver": 2, "Bronze": 0},
    {"Nation": "Japan", "Gold": 1, "Silver": 1, "Bronze": 0},
    {"Nation": "China", "Gold": 0, "Silver": 1, "Bronze": 0},
    {"Nation": "Germany", "Gold": 1, "Silver": 0, "Bronze": 0},
]

# Step 2: Create a list with the extracted data
medals_list = list(medals_data)

# Step 3: Print the list
for item in medals_list:
    print(item)    
    
    
import csv
import os

# Define the file path
file_path = 'c:/Users/bynoe/Music/Personal Workspace02/Programming 120/Assignment 3/nfl_offensive_stats.csv'

# Check if the file exists
if not os.path.exists(file_path):
    print(f"File not found: {file_path}")
else:
    # Open the CSV file
    with open(file_path, mode='r') as file:
        # Read the CSV data
        csv_reader = csv.DictReader(file)
        
        # Initialize a dictionary to store the sum of passing yards for each QB
        qb_passing_yards = {}
        
        # Process each row in the CSV
        for row in csv_reader:
            position = row['Position']  # Assuming the column name for position is 'Position'
            player = row['Player']      # Assuming the column name for player is 'Player'
            passing_yards = int(row['Passing Yards'])  # Assuming the column name for passing yards is 'Passing Yards'
            
            if position == 'QB':
                if player not in qb_passing_yards:
                    qb_passing_yards[player] = 0
                qb_passing_yards[player] += passing_yards
        
        # Sort the QBs by the sum of passing yards in descending order
        sorted_qbs = sorted(qb_passing_yards.items(), key=lambda x: x[1], reverse=True)
        
        # Print the results
        for player, yards in sorted_qbs:
            print(f'{player}: {yards} passing yards')