      PROGRAM SQRT

      IMPLICIT NONE
      REAL, PARAMETER :: E = 0.0001
      REAL :: NUM, X1, X2, RESULT

      PRINT *, 'PICK NUMBER TO BE ROOTED.'

      READ *, NUM

      IF (NUM < 0.0) THEN
         PRINT *, 'NO REAL ROOT'
      ELSE
         IF (NUM == 0) THEN
            RESULT = 0.0
         ELSE
            X1 = NUM
            X2 = 1
            DO WHILE (ABS(X1 - X2) > E)
               X1 = (X1 + X2) / 2.0
               X2 = NUM / X1
               PRINT *, 'CURRENT VALUES: ', X1, ' AND ', X2
            END DO
         END IF
         PRINT *, 'THE SQUARE ROOT OF ', NUM, ' IS: ', X1
      END IF

      END PROGRAM SQRT
       
