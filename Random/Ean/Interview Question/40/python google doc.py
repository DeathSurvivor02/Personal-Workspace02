import requests

# URL of the published Google Doc
url = "https://docs.google.com/document/d/e/2PACX-1vRMx5YQlZNa3ra8dYYxmv-QIQ3YJe8tbI3kqcuC7lQiZm-CSEznKfN_HYNSpoXcZIV3Y_O3YoUB1ecq/pub"

# Send a GET request to fetch the document's content
response = requests.get(url)

# Check the response status
if response.status_code == 200:
    content = response.text  # This contains the HTML of the page
    print(content)  # Print or process the content
else:
    print(f"Failed to fetch the document. Status code: {response.status_code}")
