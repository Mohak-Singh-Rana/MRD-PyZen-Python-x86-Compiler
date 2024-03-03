# Define a list
fruits = ["apple", "banana", "cherry"]

# Use the 'in' keyword to check if "apple" is in the list
if "apple" \
in \
        fruits:
    print("Yes, 'apple' is in the fruits list")
else:
    print("No, 'apple' is not in the fruits list")

if 1900 < year < 2100 and 1 <= month <= 12 \
  and 1 <= day <= 31 and 0 <= hour < 24 \
  and 0 <= minute < 60 and 0 <= second < 60:   # Looks like a valid date
    return 1
