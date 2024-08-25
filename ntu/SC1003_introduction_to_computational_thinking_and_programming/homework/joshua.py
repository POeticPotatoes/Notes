productInfo = {
        "1": """WHAT THIS PRODUCT IS ABOUT: AIA Guaranteed Protect Plus (III) is designed as a single solution that offers wider coverage for your protection needs.
                  With its unique multiplier feature, it gives you the ability to boost your coverage by up to 5 times while ensuring affordability. This plan also provides
                  stable cash value that is accumulated over time.""",
        "2": """WHAT THIS PRODUCT IS ABOUT: Safeguard yourself and your loved ones against death, as well as disability and 150 multi-stage critical illnesses with the
                  addition of comprehensive riders. All while enjoying the flexibility to refine your investments with professional guidance, rejig your coverage to suit your
                  goals for each life stage, and more."""
        }

def getInformation():
     print("""These are the Life Insurance Products available:
          AIA Guaranteed Protect Plus (III) [1]
          AIA Pro Lifetime Protector (II) [2]
          AIA Secure Flexi Term [3]
          DIRECT-AIA Term Cover [4]
          DIRECT-AIA Whole Life Cover [5]""")

     while True:
        life_product = str(raw_input("Enter the product you are interested in [1/2], or enter [Q] to quit: ")).upper()

        if life_product in productInfo:
            print(productInfo[life_product])
            return True

        if life_product == "Q":
            return False

        print("Please enter a valid input")

getInformation()

# elif product == "L":
#     if not getInformation():
#         # quit the program
#     # Get all the information required here
#     
