/* -*- c-file-style: "k&r" -*-
 *
 *
 * FIXME missing license
 *
 */
#ifndef VCF_H
#define VCF_H

typedef struct {
     char *chrom;
     long int pos; /* zero offset */
     char *id;
     char ref;
     char alt;
     int qual;
     char *filter;
     char *info;
} var_t;

typedef struct {
      int ref_fw;
      int ref_rv;
      int alt_fw;
      int alt_rv;
} dp4_counts_t;


void vcf_write_header(FILE *stream, const char *srcprog, const char *reffa);

void vcf_new_var(var_t **var);
void vcf_free_var(var_t **var);

void vcf_var_sprintf_info(var_t *var,
                          const int *dp, const float *af, const int *sb,
                          const dp4_counts_t *dp4,
                          const int is_indel, const int is_consvar);
void vcf_write_var(FILE *stream, const var_t *var);

#endif