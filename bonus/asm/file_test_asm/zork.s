.name "Zork"
.comment "Just a basic living program"

	sti r1, %12, %1
	ld %0, r2
	live %1
	zjmp %12
