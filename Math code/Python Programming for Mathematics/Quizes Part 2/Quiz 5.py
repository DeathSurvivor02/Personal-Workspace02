""" Write a Python function name_lookup that takes a string first_name that corresponds to one of "Duaine", "Peter", or "Bernd", and then returns their corresponding last name "Lewis", "Chami", or "Sing", respectively. If first_name doesn't match any of those strings, return the string "Error: Not an instructor"."""

def name_lookup(first_name):
    
    if first_name == "Duaine":
        return "Lewis"
    elif first_name == "Peter":
        return "Chami"
    elif first_name == "Bernd":
        return "Sing"
    else:
        return "Error: Not an instructor"