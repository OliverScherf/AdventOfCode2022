set (LIST_OF_SANITIZERS "")
list(APPEND LIST_OF_SANITIZERS
  address
  leak
  undefined
  # memory
)

list(
  JOIN
  LIST_OF_SANITIZERS
  ","
  SANITIZERS)

add_compile_options(-fsanitize=${SANITIZERS})
add_link_options(-fsanitize=${SANITIZERS})
