# --------------------------  Traffic Light Checker  --------------- 
# ---------------------- Author : Jafar Mesgarian ------------------
# ------------------- Presented to : HIRSCH Maschinenbau -----------
# --------------------- Software Version : Python  -----------------
# ------------------------   Date : 2022/Nov/08 --------------------
import string
Evaluation = " A C C E P T "
EvaBool = True

SEQ = input()
#--- waiting for Input from STDIN ----------------------------------

SEQL = len(SEQ)					# lenght of the Input
SEQ2 = SEQ[0]					# Define a new Sequence

for i in range(SEQL//2):			# Remove Spaces from SEQ
	SEQ2 += SEQ[(i+1) * 2]

SEQ = SEQ2;					# Put to the first Sequence
SEQL = len(SEQ)					# New length of the SEQ

#---  Rule No.1 : Check the Valid Charachters in the Input ---------
#===================================================================
for i in range(SEQL):
	if (SEQ[i] != 'R' and SEQ[i] != 'G' and SEQ[i] != 'Y' and SEQ[i] != 'X' and SEQ[i] != 'C' and SEQ [i] != 'P') :
		Evaluation = "\nR E J E C T (Rule No.1)"
		EvaBool = False

#---  Rule No.2 : The Sequence doesn't start with "R" ----------------
#====================================================================
if ((SEQ[0] != 'R' ) and EvaBool) :
		Evaluation = "\nR E J E C T (Rule No.2)"
		EvaBool = False

#--- Rule No.3 : No color may be repeated   --------------------------
#=====================================================================
if (EvaBool) :
	for i in range (SEQL-1) :
		if (SEQ[i] == SEQ[i+1])	:
			Evaluation = "\nR E J E C T (Rule No.3)"	
			EvaBool = False


	


		
