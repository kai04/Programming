.PHONY: clean All

All:
	@echo "----------Building project:[ Programming-master - Debug ]----------"
	@"$(MAKE)" -f  "Programming-master.mk"
clean:
	@echo "----------Cleaning project:[ Programming-master - Debug ]----------"
	@"$(MAKE)" -f  "Programming-master.mk" clean
