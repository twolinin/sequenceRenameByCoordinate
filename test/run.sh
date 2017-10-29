blastResultFormat6=$1
inputSequenceData=$2
outputFileName=$3

awk '{if(name!=$1){print $0;name=$1;}}' $blastResultFormat6 | sort -k2,2 -k9,9n > blastUnique
awk '{print $1}' $inputSequenceData > headerClearSeq.fasta

../reName blastUnique headerClearSeq.fasta > $outputFileName


