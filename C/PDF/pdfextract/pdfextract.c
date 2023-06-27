#include <pdfio.h>
#include <pdfio-content.h>
#include <string.h>

int
main()
{
	pdfio_file_t *pdf = pdfioFileOpen("1.pdf", NULL, NULL, NULL, NULL);

	size_t		i, j;
	size_t		count;
	size_t		bytes;
	size_t		num_stream;
	pdfio_obj_t	*page;
	pdfio_stream_t	*st;
	char		buffer[4000];
	bool		first;
	
	for (i = 0, count = pdfioFileGetNumPages(pdf); i < count; i++) {
		if ((page = pdfioFileGetPage(pdf, i)) == NULL) {
			continue;
		}

		num_stream = pdfioPageGetNumStreams(page);

		for (j = 0; j < num_stream; j++) {
			if ((st = pdfioPageOpenStream(page, j, true)) == NULL) {
				continue;
			}
			first = true;
			while (pdfioStreamGetToken(st, buffer, sizeof(buffer))) {
				if (buffer[0] == '(') {
					if (first) {
						first = false;
					} else {
						putchar(' ');
					}

					fputs(buffer + 1, stdout);
				}
				else if (!strcmp(buffer, "Td") || !strcmp(buffer, "TD") || !strcmp(buffer, "T*") || !strcmp(buffer, "\'") || !strcmp(buffer, "\"")) {
						putchar('\n');
						first = true;
					}
			}
			if (!first) {
				putchar('\n');
			}
			pdfioStreamClose(st);
		}
	}

	pdfioFileClose(pdf);
	
	return 0;
}
	
