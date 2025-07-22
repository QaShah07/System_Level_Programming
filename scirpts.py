import pandas as pd
from googletrans import Translator

# Step 1: Read the Excel File
input_file = "/Users/qashah07/Desktop/BLO Praptra Vitran-2025.xls"
df = pd.read_excel(input_file)

# Step 2: Function to convert Kruti Dev to Unicode Hindi
# Note: This is a simplified version; real conversion needs a full mapping
def kruti_to_unicode(text):
    # You should replace this with full mapping logic or use an external converter
    conversions = {
        'd': 'क', 'k': 'ा', 'j': 'ि', 'Z': 'ह', 'e': 'र',
        'f': 'ा', 'u': 'न', 'v': 'े', 'l': 'ि'
        # Add more mappings as needed
    }
    result = ""
    for char in text:
        result += conversions.get(char, char)
    return result

# Step 3: Apply Conversion to All Cells
def convert_df_kruti_to_unicode(df):
    for col in df.columns:
        df[col] = df[col].astype(str).apply(kruti_to_unicode)
    return df

df_unicode = convert_df_kruti_to_unicode(df)

# Step 4: Translate Hindi Unicode to English using Google Translate
translator = Translator()

def translate_to_english(text):
    try:
        translated = translator.translate(text, src='hi', dest='en')
        return translated.text
    except:
        return text

df_english = df_unicode.copy()
for col in df_unicode.columns:
    df_english[col] = df_unicode[col].astype(str).apply(translate_to_english)

# Step 5: Save the result
df_english.to_excel("translated_output.xlsx", index=False)
