# sequenceRenameByCoordinate

blastn -query query.fasta -db referenceDB -task blastn -evalue 0.0001 -outfmt 6 > blastResult
awk '{if(name!=$1){print $0;name=$1;}}' blastResult | sort -k2,2 -k9,9n > blastUnique
awk '{print $1}' query.fasta > headerClear.fasta
./reName blastUnique headerClear.fasta > headerRename.fasta

