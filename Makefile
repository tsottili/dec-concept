.PHONY: clean All

All:
	@echo "----------Building project:[ dec-concept - Debug ]----------"
	@cd "dec-concept" && "$(MAKE)" -f  "dec-concept.mk"
clean:
	@echo "----------Cleaning project:[ dec-concept - Debug ]----------"
	@cd "dec-concept" && "$(MAKE)" -f  "dec-concept.mk" clean
