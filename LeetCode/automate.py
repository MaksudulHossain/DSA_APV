import subprocess
import pandas as pd

def run_conv(phims_value):
    # Modify file.txt based on the phims value
    with open("file.txt", "r") as file:
        lines = file.readlines()
    
    # Assuming phims is somewhere in file.txt; this updates it
    with open("file.txt", "w") as file:
        for line in lines:
            if "phims" in line:
                line = f"phims {phims_value}\n"
            file.write(line)
    
    # Run conv script to generate conv_out.txt
    subprocess.run(["conv", "-u", "file.txt"])

def run_cppa():
    # Run cppa script to generate the file_ppa.csv
    subprocess.run(["cppa", "-a", "thing1", "-b", "conv_out.txt", "-c", "thing3"])

def process_files():
    # Initialize a list to store frequency data
    frequency_data = []
    
    for phims_value in range(6):  # phims ranges from 0 to 5
        # Run the conv and cppa scripts
        run_conv(phims_value)
        run_cppa()

        # Read the generated file_ppa.csv to extract frequency
        ppa_df = pd.read_csv("file_ppa.csv")
        frequency_data.append(ppa_df["frequency"].values[0])  # Assuming single value in the column

        # Save the CSV for each phims
        ppa_df.to_csv(f"file_ppa_{phims_value+1}.csv", index=False)
    
    return frequency_data

def generate_unified_ppa():
    # Combine all individual file_ppa_X.csv into unified_ppa.csv
    all_ppa_df = pd.DataFrame()
    
    for phims_value in range(6):
        ppa_df = pd.read_csv(f"file_ppa_{phims_value+1}.csv")
        all_ppa_df = pd.concat([all_ppa_df, ppa_df], ignore_index=True)
    
    all_ppa_df.to_csv("unified_ppa.csv", index=False)

def report_sensitivity(frequency_data):
    # Prepare data for final_sensitivity.csv
    sensitivity_df = pd.DataFrame({
        "phims": [0, 1, 2, 3, 4, 5],
        "frequency": frequency_data
    })
    sensitivity_df.to_csv("final_sensitivity.csv", index=False)

def main():
    # Taking user input
    print("Please enter the parameter and range: ")
    param = input("--parameter ").strip()
    phims_range = input("--range ").strip()
    
    # Assuming range is in the format "0 5"
    start, end = map(int, phims_range.split())

    # Process files for the specified range
    frequency_data = process_files()

    # Generate unified_ppa.csv
    generate_unified_ppa()

    # Report sensitivity and save to final_sensitivity.csv
    report_sensitivity(frequency_data)

    # Print the results in the console
    print("Sensitivity Report:")
    print(frequency_data)

if __name__ == "__main__":
    main()
